#ifndef HIERARCH
#define HIERARCH

#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
#include <assert.h>

#include <sparsepp/spp.h>
#include <avltree/avltree.h>

#include <hierarch/types.h>
#include <hierarch/node.h>
#include <hierarch/avl_bridge.h>
#include <hierarch/result.h>
#include <hierarch/context.h>
#include <hierarch/tests.h>

namespace Hierarch {
  const context_id_t MIN_CTX_ID = std::numeric_limits<context_id_t>::min();
  const context_id_t MAX_CTX_ID = std::numeric_limits<context_id_t>::max();
  const type_id_t MIN_TYPE_ID = std::numeric_limits<type_id_t>::min();
  const type_id_t MAX_TYPE_ID = std::numeric_limits<type_id_t>::max();
  const node_id_t MIN_NODE_ID = std::numeric_limits<node_id_t>::min();
  const node_id_t MAX_NODE_ID = std::numeric_limits<node_id_t>::max();
  std::mt19937 rng;
  std::uniform_int_distribution<std::mt19937::result_type> ctx_dist(MIN_CTX_ID, MAX_CTX_ID);
  std::uniform_int_distribution<std::mt19937::result_type> type_dist(MIN_TYPE_ID, MAX_TYPE_ID);
  std::uniform_int_distribution<std::mt19937::result_type> node_dist(MIN_NODE_ID, MAX_NODE_ID);
  spp::sparse_hash_map<context_id_t, Context> contexts;
  Context *ctx = NULL;
  Node *node_cursor = NULL;
  bool ran_init = false;

  void init();

  type_id_t create_type();
  void delete_type(type_id_t type_id);

  context_id_t create_context();
  Context *switch_context(context_id_t context_id);
  void delete_context();
  Context *current_context();

  node_id_t add_leaf();
  void select_node(node_id_t node_id);
  void apply_type(node_id_t node_id, type_id_t node_type);

  void start_benchmark();
  void end_benchmark();
  context_id_t gen_context_id();
  type_id_t gen_type_id();
  node_id_t gen_node_id();

  bool benchmark = false;
  unsigned long num_basic_ops = 0;
  inline void basic_op();
}
#endif
