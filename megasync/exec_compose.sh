# Usage: megasimplesync [local folder] [remote folder]
# RUN megasimplesync /tmp $REMOTE_FOLDER

docker-compose exec sync_2018 "/bin/sh megasimplesync $LOCAL_FOLDER $REMOTE_FOLDER"
