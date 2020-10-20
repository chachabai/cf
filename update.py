import os
import sys

# for linux
#os.system('find -name .vscode | xargs rm -rf')

#os.system('git init')
os.system('git add .')

#os.system('git remote rm origin')
#os.system('git remote add origin git@github.com:chachabai/cf.git')
if len(sys.argv) < 2:
	os.system('git commit -m "update"')
else:
	os.system('git commit -m "' + ' '.join(sys.argv[1:]) + '"')
os.system('git push origin master')
