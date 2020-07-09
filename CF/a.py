import os,shutil;
map(lambda x:shutil.move(x,x.replace("educational","edu")),os.listdir("."))
