# build the vulnerable zlib once, shared by both challenges
git clone https://github.com/madler/zlib
cd zlib && git checkout v1.2.11   # or 1.2.12, any version before the fix
./configure && make