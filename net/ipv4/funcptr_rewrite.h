/*
 * Some functions are defined as static functions, passed to function pointers
 * and then called in another module. The static keyword of these functions need
 * to be removed and their declarations are in thie header. The header file should
 * be included after rewriting.
 */
#ifndef _FUNCPTR_REWRITE_H
#define _FUNCPTR_REWRITE_H


// tcp_request_sock_ops

void tcp_v4_reqsk_send_ack(const struct sock *sk, struct sk_buff *skb,
                  struct request_sock *req);

void tcp_v4_send_reset(const struct sock *sk, struct sk_buff *skb);


// tcp_request_sock_ipv4_ops

void tcp_v4_init_req(struct request_sock *req,
                const struct sock *sk_listener,
                struct sk_buff *skb);

struct dst_entry *tcp_v4_route_req(const struct sock *sk, 
                      struct flowi *fl, 
                      const struct request_sock *req,
                      bool *strict);

__u32 tcp_v4_init_sequence(const struct sk_buff *skb);

int tcp_v4_send_synack(const struct sock *sk, struct dst_entry *dst,
                  struct flowi *fl,
                  struct request_sock *req,
                  struct tcp_fastopen_cookie *foc,
                  enum tcp_synack_type synack_type);


#endif  /* _FUNCPTR_REWRITE_H */

