 #!/usr/bin/env python
# coding=utf-8
import os
path=''

print("-----------------------------------------------")

os.system("rm tags ")

print("     create ctag                               ")

os.system("ctags -R .")

os.system("rm cscope* ")

#os.system("cscope -Rbq")

path = str(os.getcwd())

os.system("find "+ path + " -name '*.h' > cscope.files ")
os.system("find "+ path + " -name '*.c' >> cscope.files ")
os.system("find "+ path + " -name '*.v' >> cscope.files ")
os.system("find "+ path + " -name '*.sv' >> cscope.files ")
os.system("find "+ path + " -name '*.svh' >> cscope.files ")

print("     create cscope                           ")

os.system("cscope -bqk ")

print("-----------------------------------------------")

