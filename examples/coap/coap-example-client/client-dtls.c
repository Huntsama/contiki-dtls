#include <stdio.h>
#include <stdlib.h>
#include "contiki.h"
#include "contiki-net.h"
#include "coap-engine.h"
#include "tinydtls.h"
#include "dtls.h"

#define SERVER_IP "coaps://[fe80::202:2:2:2]"
#define SERVER_PORT UIP_HTONS(COAP_DEFAULT_SECURE_PORT)

static dtls_context_t *dtls_context;

static void init_dtls(void) {
    static dtls_handler_t cb = {
        .write = send_to_peer,
        .read = read_from_peer,
        .event = handle_event,
        .get_psk_info = get_psk_info
    };

    uip_ipaddr_t server_addr;
    uip_ip6addr(&server_addr, 0xfe80, 0, 0, 0, 0x0202, 0x0202, 0x0202, 0x0202);
    struct uip_udp_conn *client_conn = udp_new(&server_addr, SERVER_PORT, NULL);

    dtls_context = dtls_new_context(client_conn);
    if (!dtls_context) {
        LOG_ERR("Failed to create DTLS context\n");
        PROCESS_EXIT();
    }

    dtls_set_handler(dtls_context, &cb);
}

PROCESS(coap_dtls_client, "CoAP DTLS Client");
AUTOSTART_PROCESSES(&coap_dtls_client);

PROCESS_THREAD(coap_dtls_client, ev, data) {
    PROCESS_BEGIN();

    dtls_init();
    init_dtls();

    while(1) {
        PROCESS_WAIT_EVENT();
        if(ev == tcpip_event) {
            dtls_handle_read(dtls_context);
        }
    }

    PROCESS_END();
}
