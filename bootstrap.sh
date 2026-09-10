#!/usr/bin/env bash

set -Eeuo pipefail

trap 'echo "❌ 오류 발생: line $LINENO" >&2' ERR

NODE_MAJOR=24

echo "========================================"
echo "🚀 개발 환경 설치 시작"
echo "========================================"

# ------------------------------------------------------------
# 0. 과거의 잘못된 NodeSource 설정 정리
# ------------------------------------------------------------

echo "🧹 기존 NodeSource 설정 정리..."

sudo rm -f \
  /etc/apt/sources.list.d/nodesource.list \
  /etc/apt/sources.list.d/nodesource.sources \
  /etc/apt/keyrings/nodesource.gpg

# 예전 스크립트가 /etc/apt/sources.list에 직접 넣은 경우도 방어
if sudo grep -q "https://nodesource.com" /etc/apt/sources.list 2>/dev/null; then
  sudo sed -i '\|https://nodesource.com|d' /etc/apt/sources.list
fi

# ------------------------------------------------------------
# 1. 시스템 패키지
# ------------------------------------------------------------

echo "🔄 패키지 목록 업데이트..."

sudo apt-get update

echo "📦 개발 도구 설치..."

sudo apt-get install -y \
  curl \
  ca-certificates \
  gnupg \
  git \
  git-lfs \
  tmux \
  wget \
  build-essential \
  python3 \
  python3-dev \
  python3-pip \
  python3-venv \
  pkg-config \
  tree \
  vim \
  nano \
  htop \
  openssh-client \
  graphviz

# ------------------------------------------------------------
# 2. Git LFS
# ------------------------------------------------------------

echo "🔧 Git LFS 초기화..."

git lfs install

# ------------------------------------------------------------
# 3. NodeSource 공식 저장소
# ------------------------------------------------------------

echo "🟢 Node.js ${NODE_MAJOR} LTS 저장소 등록..."

sudo mkdir -p /etc/apt/keyrings

curl -fsSL \
  https://deb.nodesource.com/gpgkey/nodesource-repo.gpg.key \
  | sudo gpg --dearmor --yes \
      -o /etc/apt/keyrings/nodesource.gpg

sudo chmod 644 /etc/apt/keyrings/nodesource.gpg

echo \
  "deb [signed-by=/etc/apt/keyrings/nodesource.gpg] https://deb.nodesource.com/node_${NODE_MAJOR}.x nodistro main" \
  | sudo tee /etc/apt/sources.list.d/nodesource.list > /dev/null

echo "🔄 NodeSource 저장소 반영..."

sudo apt-get update

# ------------------------------------------------------------
# 4. Node.js
# ------------------------------------------------------------

echo "📦 Node.js ${NODE_MAJOR} LTS 설치..."

sudo apt-get install -y nodejs

echo
echo "📌 Node.js:"
node --version

echo "📌 npm:"
npm --version

# ------------------------------------------------------------
# 5. npm global 패키지를 사용자 디렉터리에 설치
#
# sudo npm install -g 사용 안 함
# ------------------------------------------------------------

echo "🔧 npm global 사용자 경로 구성..."

mkdir -p "$HOME/.local"

npm config set prefix "$HOME/.local"

export PATH="$HOME/.local/bin:$PATH"

# 이후 로그인에서도 PATH 유지
if ! grep -Fq 'export PATH="$HOME/.local/bin:$PATH"' "$HOME/.profile" 2>/dev/null; then
  echo 'export PATH="$HOME/.local/bin:$PATH"' >> "$HOME/.profile"
fi

# bash shell에서도 바로 사용
if ! grep -Fq 'export PATH="$HOME/.local/bin:$PATH"' "$HOME/.bashrc" 2>/dev/null; then
  echo 'export PATH="$HOME/.local/bin:$PATH"' >> "$HOME/.bashrc"
fi

# ------------------------------------------------------------
# 6. AI CLI
# ------------------------------------------------------------

echo "🤖 OpenAI Codex CLI 설치..."

npm install -g @openai/codex@latest

echo "🤖 Anthropic Claude Code 설치..."

npm install -g @anthropic-ai/claude-code@latest

# ------------------------------------------------------------
# 7. Claude 계정/팀 전환 도구 (사용자 전역 설치)
#
# https://github.com/realiti4/claude-swap
# Python 3.12는 uv가 관리하므로 시스템 Python은 변경하지 않음.
# 로그인/팀 인증은 각 컴퓨터에서 별도로 등록.
# ------------------------------------------------------------

echo "🔀 Claude Swap (cswap) 설치..."

if ! command -v uv >/dev/null 2>&1; then
  curl -fsSL https://astral.sh/uv/install.sh \
    | env UV_INSTALL_DIR="$HOME/.local/bin" UV_NO_MODIFY_PATH=1 sh
fi

# 이미 설치된 경우에도 재실행 가능. 최신 안정 버전으로 설치/업데이트.
UV_TOOL_BIN_DIR="$HOME/.local/bin" uv tool install --python 3.12 --upgrade claude-swap

# ------------------------------------------------------------
# 8. 설치 결과
# ------------------------------------------------------------

echo
echo "========================================"
echo "✅ 개발 환경 설치 완료"
echo "========================================"
echo

printf "%-14s %s\n" "Node.js:" "$(node --version)"
printf "%-14s %s\n" "npm:" "$(npm --version)"
printf "%-14s %s\n" "Git:" "$(git --version)"
printf "%-14s %s\n" "Git LFS:" "$(git lfs version)"
printf "%-14s %s\n" "Python:" "$(python3 --version)"
printf "%-14s %s\n" "Codex:" "$(codex --version)"
printf "%-14s %s\n" "Claude Code:" "$(claude --version)"
printf "%-14s %s\n" "uv:" "$(uv --version)"
printf "%-14s %s\n" "Claude Swap:" "$(cswap --version)"

echo
cat <<'CSWAP_HELP'
🔀 각 컴퓨터/서버에서 최초 1회 팀 등록:
  1. claude 실행 후 /login 으로 첫 팀 선택
  2. 별도 터미널에서 cswap add --alias team1
  3. Claude Code의 /login 으로 다른 팀 선택 후 cswap add --alias team2
     (팀 수만큼 반복. 같은 이메일이어도 팀별로 등록 가능)

  /logout 을 먼저 실행하면 저장한 인증이 무효화될 수 있습니다.
  cswap list                      # 등록된 팀과 사용량 확인
  cswap switch team1              # 수동 전환
  cswap auto --threshold 90        # 사용량 90%부터 자동 전환 (전경 실행)
  tmux new-session -d -s cswap-auto 'cswap auto --threshold 90'
                                  # SSH 종료 후에도 유지 (재부팅 후 다시 실행)
  tmux attach -t cswap-auto        # 자동 전환 로그 확인

설치는 현재 사용자 전역에 적용됩니다. 새 터미널에서 cswap을 사용할 수 있습니다.
팀 로그인과 자동 전환 프로세스는 각 서버에서 별도로 관리합니다.
CSWAP_HELP

echo "🎉 완료!"
