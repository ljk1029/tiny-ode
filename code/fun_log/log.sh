#!/usr/bin/env bash


ARCH="$(uname -m)"

##==============================================================##
## Note(storypku): DRY broken for this self-contained script.
##==============================================================##
BOLD='\033[1m'
RED='\033[0;31m'
WHITE='\033[34m'
NO_COLOR='\033[0m'

# info
function info() {
  (echo >&2 -e "[${WHITE}${BOLD}INFO${NO_COLOR}] $*")
}

# err
function error() {
  (echo >&2 -e "[${RED}ERROR${NO_COLOR}] $*")
}

# colour
function red_print() {
  (echo >&2 -e "${RED}[RED] $* ${NO_COLOR}")
}
##==============================================================##


# 打印提示颜色
function test_log() {
    local kernel_version="$(uname -r)"
    info "Realtime kernel ${kernel_version} found."
    error "Realtime kernel ${kernel_version} found." 
    red_print 'red print'
}


test_log