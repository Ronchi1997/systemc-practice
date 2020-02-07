#include "fifo.h"
#include "tb.h"

int sc_main(int argc, char** argv) {
  fifo f("fifo");
  tb test("testbench");
  test.read_port(f);
  test.write_port(f);
  sc_start(10, SC_NS);
  return 0;
}
