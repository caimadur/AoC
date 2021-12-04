/forward/ {
    len += $2
    depth += aim * $2
}
/down/ { aim += $2 }
/up/ { aim -= $2 }
END { printf("Length x depth: %d x %d = %d\n", len, depth, len * depth) }
