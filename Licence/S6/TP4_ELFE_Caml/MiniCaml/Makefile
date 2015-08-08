MODULES=lexical syntaxe evaluation minicaml
MODULESMLI=$(addsuffix .mli, $(MODULES))
MODULESML=$(addsuffix .ml, $(MODULES))
MODULESCMI=$(addsuffix .cmi, $(MODULES))
MODULESCMO=$(addsuffix .cmo, $(MODULES))

.PHONY= clean doc

doc:
	ocamldoc -html -t miniCaml -d Doc $(MODULESMLI)

minicaml.zip: 
	zip $@ $(MODULESMLI) $(MODULESML) Doc/* Makefile

%.cmi: %.mli
	ocamlc -c $<

%.cmo: %.ml %.cmi
	ocamlc -c $<

minicaml: $(MODULESCMI) $(MODULESCMO)
	ocamlc -o $@ $(MODULESCMO) minicaml.ml

clean:
	rm -f *~
	rm -f *.cmi *.cmo
