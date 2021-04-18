fn foo_1(x: i32) -> i32 {
    x
}

fn foo_2(x: &'static str) -> &'static str {
    x
}

fn main() {
    assert_eq!(foo_1(1), 1);
    assert_eq!(foo_2("1"), "1");
}