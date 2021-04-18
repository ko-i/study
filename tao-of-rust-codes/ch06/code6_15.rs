type MathOp = fn(i32, i32) -> i32;

fn math(op: MathOp, a: i32, b: i32) -> i32 {
    op(a, b)
}