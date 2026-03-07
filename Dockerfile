FROM debian:bookworm-slim

ENV DEBIAN_FRONTEND=noninteractive

# 1. 필수 도구 설치 및 사용자 생성
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential cmake gdb git vim sudo bash neofetch ca-certificates && \
    # 'node' 대신 운혁님의 아이덴티티를 살린 사용자 생성 (예: dev)
    useradd -m -s /bin/bash dev && \
    echo "dev ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers && \
    apt-get clean && rm -rf /var/lib/apt/lists/*

WORKDIR /home/dev/workspace

# 2. 소유권 변경 (마운트 시 권한 문제 방지)
RUN chown -R dev:dev /home/dev/workspace

USER dev

# neofetch로 기분 좋게 시작
CMD ["/bin/bash", "-c", "neofetch; sleep infinity"]