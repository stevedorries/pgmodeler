Compiling
---------

This document describes a simple way how to compile pgModeler. Please read it carefully so that no step is forgotten and compromising the entire process.

Compiling Requirements
-------------------------

* GCC Development Tools 4.4 or above (Windows and Linux)
* Xcode 4.5 or above (Mac OSX only)
* Qt 4.8.x library (qt-project.org)
* libXML2 library (www.xmlsoft.org)
* libpq library (www.postgresql.org)
* pgModeler source (github.com/pgmodeler/pgmodeler/tags)

The process
-----------

<strong>Note to Linux</strong> The compilation script make use of 'pkgconfig' tool to find the correct path to PostgreSQL and libXML2 include/libs so make sure that executing the commands below will produce a similar result as follow:

<code>$ pkg-config libpq --cflags  --libs
> -I/usr/include -L/usr/lib64/libpq.so
</code>

<code>$ pkg-config libxml-2.0 --cflags --libs
> -I/usr/include/libxml2  -lxml2
</code>

If some error is returned after run the above commands check the installation of PostgreSQL and libXML2. The compilation will fail if these dependencies could not be resolved.

<strong>Specific for Ubuntu:</strong> If you are experiencing linkage errors related to libpq even having PostgreSQL correctly installed try to create the file "/usr/lib/pkgconfig/libpq.pc" with the following content:

     prefix=/usr
     libdir=${prefix}/lib/postgresql/[VERSION]/lib
     includedir=${prefix}/include/postgresql

     Name: LibPQ
     Version: 5.0.0
     Description: Library PQ
     Requires:
     Libs: -L${libdir}/libpq.so -lpq
     Cflags: -I${includedir}

<strong>Note to Windows/MacOSX:</strong> Before starting the compilation, check in the file 'pgmodeler.pro' if the variables PGSQL_(INC|LIB) and XML_(INC|LIBS) points to the correct paths relative to your system.

To compile the pgModeler type (in the root folder of the source code):

     $ qmake pgmodeler.pro
     $ make
     $ make install

If the build is successful the executable 'pgmodeler' and some directories will be created in the build/ folder. Copy the contents of this folder to any other location you want.

Environment Variables
---------------------

Four own environment variables are used by pgModeler to access the folders schemas/, conf/, plugins/ and lang/. If you want to configure directories cited in deferent paths use the following variables:

* PGMODELER_SCHEMAS_DIR -> stores the full path the directory schemas/
* PGMODELER_CONF_DIR -> stores the full path the directory conf/
* PGMODELER_LANG_DIR -> stores the full path the directory lang/
* PGMODELER_PLUGINS_DIR -> stores the full path the directory plugins/

Additionally, pgModeler need to know where to find the libraries required for the execution (Qt Library, LibXML and libpq) for which you should enter the full path in the variable LD_LIBRARY_PATH (Unix) or PATH (Windows), if not already configured.

To provide the interface translation pgModeler checks the variable LANG (Unix). To use a specific translation, change the value of this variable. So far, the pgModeler only supports the U.S. English (en_US) language.

Finally, as a convenience, the script 'start-pgmodeler.(sh | bat)' is provided to assist the initialization of pgModeler so it is not necessary to call the executable directly or change the environment variables on your operating system.

<strong>Note:</strong> You may need to edit the parameters of the script depending on configuration of your operating system.
