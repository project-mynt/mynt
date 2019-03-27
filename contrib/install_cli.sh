 #!/usr/bin/env bash

 # Execute this file to install the mynt cli tools into your path on OS X

 CURRENT_LOC="$( cd "$(dirname "$0")" ; pwd -P )"
 LOCATION=${CURRENT_LOC%Mynt-Qt.app*}

 # Ensure that the directory to symlink to exists
 sudo mkdir -p /usr/local/bin

 # Create symlinks to the cli tools
 sudo ln -s ${LOCATION}/Mynt-Qt.app/Contents/MacOS/myntd /usr/local/bin/myntd
 sudo ln -s ${LOCATION}/Mynt-Qt.app/Contents/MacOS/mynt-cli /usr/local/bin/mynt-cli
