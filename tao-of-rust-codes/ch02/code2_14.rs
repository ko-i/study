fn math<F: Fn() -> i32>(op: F) -> i32 {
    op()
}

fn main() {
    let a = 2;
    let b = 3;

    assert_eq!(5, math(|| a + b));
    assert_eq!(6, math(|| a * b));
}