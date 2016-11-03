#!/bin/bash
#LDCONF=`ldconfig -p`
if [[ "$LDCONF" == *"libthrift"* ]]
then
        echo "Lib thrift already installed";
else
        set -ex
	rm -rf thrift*
	wget http://archive.apache.org/dist/thrift/0.9.2/thrift-0.9.2.tar.gz -O thrift-0.9.2.tar.gz
	tar -xzvf thrift-0.9.2.tar.gz
	cd thrift-0.9.2 && ./configure --without-qt4  --without-c_glib  --without-csharp --without-java --without-erlang --without-nodejs --without-lua --without-python --without-perl --without-php --without-php_extension --without-ruby --without-haskell --without-go --without-d --prefix=/usr && make && sudo make install
fi
