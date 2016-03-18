/*
Copyright (c) 2014 Microsoft Corporation. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.

Author: Leonardo de Moura
*/
#pragma once
#include "util/name.h"
#include "kernel/constraint.h"

namespace lean {
class environment;

/**
   \brief Extension context (aka API provided to macro_definitions and normalizer_extensions).
   The extension can request
   1) the environment being used.
   2) the weak head normal form of an expression.
   3) the type of an expression.
   4) registration of a new constraint.
*/
class extension_context {
public:
    virtual ~extension_context() {}
    virtual environment const & env() const = 0;
    virtual expr whnf(expr const & e) = 0;
    virtual bool is_def_eq(expr const & e1, expr const & e2) = 0;
    virtual expr check_type(expr const & e, bool infer_only) = 0;
    virtual optional<expr> is_stuck(expr const & e) = 0;
    expr infer_type(expr const & e);
};
}
