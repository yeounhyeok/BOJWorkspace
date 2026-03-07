# 1. 베이스 이미지 (Node.js 및 경량화된 Debian 기반)
FROM debian:bookworm-slim

# 2. 패키지 설치 중 상호작용 프롬프트 방지
ENV DEBIAN_FRONTEND=noninteractive

# 3. 필수 개발 도구 설치 (C++ 빌드 툴 포함)
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    gdb \
    git \
    vim \
    sudo \
    bash \
    git \
    neofetch && \
    # 4. 권한 설정: 기본 내장된 'node' 사용자가 비밀번호 없이 sudo를 사용하도록 설정
    echo "node ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers && \
    # 5. 캐시 정리 (이미지 용량 최소화)
    apt-get clean && rm -rf /var/lib/apt/lists/*

# 6. 작업 디렉토리 설정 (맥북의 로컬 폴더가 마운트될 위치)
WORKDIR /home/node/workspace

# 7. 루트 권한을 버리고 안전한 일반 사용자 계정으로 전환 (보안 권장 사항)
USER node

# 8. 컨테이너가 바로 종료되지 않고 유지되도록 설정
CMD ["sleep", "infinity"]