#pragma once

// These are handcrafted or otherwise tricky to generate with our tool chain

static const char entry_wast[] = R"=====(
(module
 (import "env" "assert" (func $assert (param i32 i32)))
 (import "env" "now" (func $now (result i32)))
 (table 0 anyfunc)
 (memory $0 1)
 (export "memory" (memory $0))
 (export "entry" (func $entry))
 (export "init" (func $init))
 (export "apply" (func $apply))
 (func $entry
  (i32.store offset=4
   (i32.const 0)
   (call $now)
  )
 )
 (func $init
 )
 (func $apply (param $0 i64) (param $1 i64)
  (call $assert
   (i32.eq
    (i32.load offset=4
     (i32.const 0)
    )
    (call $now)
   )
   (i32.const 0)
  )
 )
 (start $entry)
)
)=====";

static const char mutable_global_wast[] = R"=====(
(module
 (import "env" "assert" (func $assert (param i32 i32)))
 (table 0 anyfunc)
 (memory $0 1)
 (export "memory" (memory $0))
 (export "init" (func $init))
 (export "apply" (func $apply))
 (func $init
   (set_global $g0
     (i32.const 444)
   )
 )
 (func $apply (param $0 i64) (param $1 i64)
  (call $assert
   (i32.eq
    (get_global $g0)
    (i32.const 2)
   )
   (i32.const 0)
  )
 )
 (global $g0 (mut i32) (i32.const 2))
)
)=====";