/forward/ { len += $2 }
/down/ { depth += $2 }
/up/ { depth -= $2 }
END { printf("Length x depth: %d x %d = %d\n", len, depth, len * depth) }
