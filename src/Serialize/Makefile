
THORSANVIL_ROOT				?= $(realpath ../../)

TARGET						= ThorSerialize.slib
VERA_RULES					=	L001	L002			L004	L005	L006						\
								T001	T002	T003	T004	T005	T006	T007	T008A T008B	\
								T009A	T010	T011	T016	T017	T018	T019				\
								F001	F002														\
								M001	M002	M003
VERA_L004_MAX_LINE_LENGTH	=	max-line-length=140
VERA_PARAMS					=   $(VERA_L004_MAX_LINE_LENGTH)
VERA_RULES_ALL				=	DUMP	L001	L004	T001	T004	T007	T010	T013	T016	T019	\
								F001	L002	L005	T002	T005	T008	T011	T014	T017	Z001	\
								F002	L003	L006	T003	T006	T009	T012	T015	T018

#
# Note: SERIALIZATION_EXTERN_LIBS
#▸  ▸   Is set up in the config for any external libraries that we need.
#

FILE_WARNING_FLAGS			+= -Wno-deprecated-register
LDLIBS_EXTERN_BUILD			+= $(yaml_ROOT_LIB)
%/JsonLexer.lex.o:			FILE_WARNING_FLAGS	+= -Wno-sign-compare
%/JsonLexer1.lex.o:			FILE_WARNING_FLAGS	+= -Wno-deprecated-register

include $(THORSANVIL_ROOT)/build/tools/Makefile




