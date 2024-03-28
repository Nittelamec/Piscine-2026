#!/bin/sh

SSH_DIR="$HOME/.ssh"
if [ "$#" -gt 0 ]; then
    SSH_DIR="$1"
fi

if [ ! -f "$SSH_DIR/id_rsa" -o ! -f "$SSH_DIR/id_rsa.pub" ] && [ ! -f "$SSH_DIR/id_ed25519" -o ! -f "$SSH_DIR/id_ed25519.pub" ]; then
    echo "Could not find ssh keys"
    echo "Make sure both id_rsa and id_rsa.pub or id_ed25519 and id_ed25519.pub files exist"
    exit 1
fi

CONTAINER_ID=$(podman run -d --name ssh-quest -p 22022:22 registry.cri.epita.fr/ing/assistants/public/registry/ssh-quest:latest)

if [ "$?" -ne 0 ]; then
    exit 1
fi

podman cp "$SSH_DIR" "$CONTAINER_ID:.ssh"

if [ "$?" -ne 0 ]; then
    podman container rm ssh-quest -f
    exit 1
fi

podman exec -u 0 "$CONTAINER_ID" chown -R student .ssh
