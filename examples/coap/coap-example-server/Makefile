CONTIKI_PROJECT = coap-example-server
all: $(CONTIKI_PROJECT)

# Do not try to build on Sky because of code size limitation
PLATFORMS_EXCLUDE = sky z1

# Include CoAP resources
MODULES_REL += ./resources

CONTIKI=../../..

# MAKE_MAC = MAKE_MAC_TSCH

# Include the CoAP implementation
include $(CONTIKI)/Makefile.dir-variables
MODULES += $(CONTIKI_NG_APP_LAYER_DIR)/coap


# CFLAGS += -I$(CONTIKI)/os/net/security/tinydtls

# CFLAGS += -DMAKE_WITH_DTLS=1

MAKE_WITH_DTLS=1


include $(CONTIKI)/Makefile.include


