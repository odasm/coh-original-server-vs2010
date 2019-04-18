TEMPLATE  = subdirs
SUBDIRS = 1_readonly \
          2_formatting \
          3_changingmodel \
          4_headers \
          5_edit \
          6_treeview \
          7_selections

# install
target.path = $$[QT_INSTALL_EXAMPLES]/tutorials/modelview
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS modelview.pro 
sources.path = $$[QT_INSTALL_EXAMPLES]/tutorials/modelview
INSTALLS += target sources

symbian: include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
