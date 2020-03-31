#!/usr/bin/env bash
echo "[+] Началось резервное копирование"
tar --no-recursion -czf "files.tar.gz" *
echo "[+] Резервное копирование завершено"
# -c - create new archive
# -z - tar through gzip
# -f - use files.tar.gz
