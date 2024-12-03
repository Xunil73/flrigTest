# flrigTest
Testfiles to learn how to access flrig's xmlrpc server

1. Installation der Bibliotheken (Debian Bullseye):

libxml-xpathengine-perl
libxml-twig-perl
libxml-parser-perl
libxmlsec1-nss
libxmlsec1
libxml2
libxmlrpc-core-c3
libxmlrpc-c++8v5
libxmlrpc-core-c3-dev
libxmlrpc-c++8-dev
libxml-light-ocaml
libxml-light-ocaml-dev
libxmlrpc-epi0
libxmlrpc-epi-dev
libxmlrpc-epi0-dbg
libxmlrpc-light-ocaml-dev
libxmlrpc-lite-perl
libxmlrpcpp3d
libxmlrpcpp-dev

2. Befehl zum Kompilieren:

g++ -o flrigTest flrigTest.cpp flrigClient.h flrigClient.cpp `xmlrpc-c-config c++2 client --libs` 

- Achtung! Der String am Ende enhaelt "Backquotes" (Kommandosubstitution Bash)
  nicht mit einfachen Anfuehrungszeichen verwechseln!

