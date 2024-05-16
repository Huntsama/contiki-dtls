# CONTIKI_PROJECT = coap-example-client
CONTIKI_PROJECT = lastversion-client-dtls
# coap-example-observe-client is outdated but will be ported at a later point
all: $(CONTIKI_PROJECT)

# Do not try to build on Sky because of code size limitation
PLATFORMS_EXCLUDE = sky z1

CONTIKI=../../..

# MAKE_MAC = MAKE_MAC_TSCH
# CFLAGS += -DMAKE_WITH_DTLS=1
MAKE_WITH_DTLS=1

# Include the CoAP implementation
include $(CONTIKI)/Makefile.dir-variables
MODULES += $(CONTIKI_NG_APP_LAYER_DIR)/coap

include $(CONTIKI)/Makefile.include
