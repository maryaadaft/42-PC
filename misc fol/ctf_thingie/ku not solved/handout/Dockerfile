FROM ubuntu:20.04

RUN apt update && apt install socat gcc -y
RUN useradd -m ctf

WORKDIR /home/ctf

COPY pwn.c .
COPY flag.txt .

RUN gcc -z execstack -fno-stack-protector -o pwn pwn.c
RUN rm pwn.c

# Restrict filesystem access
RUN chmod 000 /bin/su /bin/mount /usr/bin/sudo 2>/dev/null || true
RUN rm -f /etc/passwd- /etc/shadow- /etc/group- 2>/dev/null || true

RUN chown ctf:ctf pwn flag.txt

USER ctf

ENTRYPOINT ["socat", "tcp-l:8080,fork,reuseaddr", "exec:./pwn"]
