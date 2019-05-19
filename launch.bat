@echo off

cd %1

node-gyp configure build

node -e "console.log(require('./build/Release/node_gui').create())"