#! /bin/bash

RELSCRPATH=`dirname $0`
echo $RELSCRPATH

echo ">> Cleaning mmc"
# MMCPATH=$RELSCRPATH/../mmc/
# make -f $RELSCRPATH/../Makefile PKGPATH=$MMCPATH TARGET=mmc clean

echo ">> Cleaning TSelector_SusyNtuple_Zll"
MYTSELPATH=$RELSCRPATH/../
make -f $RELSCRPATH/../Makefile PKGPATH=$MYTSELPATH TARGET=TSelector_SusyNtuple_Zll CXXFLAGSDEP="-I$RELSCRPATH/../../RootCore/include/" clean

