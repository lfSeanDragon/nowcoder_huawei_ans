#!/usr/bin/env python

import os
import sys
import time
import subprocess

def cmd(command):
    subp = subprocess.Popen(command,shell=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE,encoding="utf-8")
    subp.wait(2000)
    if subp.poll() == 0:
        print(subp.communicate()[1])
    else:
        print("失败")

if len(sys.argv) == 0 :
    sys.exit(0)

dir = sys.path[0]

argvs = ""
for i in range(1,len(sys.argv)):
    argvs=argvs+" "+sys.argv[i]

cmd("astyle --options="+dir+"/astylerc --preserve-date"+argvs)
