# Experimental

This is a first attempt to implement PDFium in PHP using FFI.
Pdfium is a C++ library supported by Google team to render, manipulate and extract data from PDF.

Contribution are welcome.

# Currently working

On PDF Document :
* Getting page count
* Iterate through Document pages

On each Page : 
* Get pages size in point
* Render a page into a .png 
* Iterate through page annotations
* Iterate through page fields

On each Annotation :
* Get the annotation type (enum) and index

On each FormField :
* Get the type (enum), value, name, alternateName, exportValue, formControlCount, formControlIndex, isChecked (for checkbox and radiobutton)

**About page rendering, this only works thanks to libvips integration, it's the only way to get a fast rendering**

Feel free to look in the tests to know how it works.

# Remaining works

There is still a lot of work to do, could be great to have the ability to edit PDF files.
At least for adding forms fields on page, and fill them.

# Development

Here is the Google pdfium repository https://pdfium.googlesource.com/pdfium/+/refs/heads/main there is some tests and C samples inside. 

The public directory contains the headers, that we have access in this repository docker image (take a look at the Dockerfile)

Note : We use pre-compiled libraries for pdfium and libvips for simplicity.

On Docker image build, libraries headers are available in `/usr/lib-pdfium` and `/usr/lib-vips` directories
