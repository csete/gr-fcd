#
# Copyright 2001,2005,2009 Free Software Foundation, Inc.
# 
# GNU Radio is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
# 
# GNU Radio is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with GNU Radio; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
# 

include $(top_srcdir)/Makefile.common


dist_gr_fcd_doc_DATA =			\
	$(top_srcdir)/README		\
	$(top_srcdir)/README.hacking

all-local: prep @generate_docs@
doc: docs            # alias

docs: prep html/index.html
html/index.html:
	@DOXYGEN@

prep:
	$(MKDIR_P) html
	$(MKDIR_P) xml

install-data-local:
	$(MKDIR_P) $(DESTDIR)$(gr_fcd_docdir)
	cp -r html $(DESTDIR)$(gr_fcd_docdir)
	cp -r xml $(DESTDIR)$(gr_fcd_docdir)

uninstall-local:
	$(RM) -fr $(DESTDIR)$(gr_fcd_docdir)/html
	$(RM) -fr $(DESTDIR)$(gr_fcd_docdir)/xml

clean-local:
	$(RM) -fr latex html man xml
