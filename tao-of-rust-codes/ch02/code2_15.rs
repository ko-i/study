fn two_times_impl() -> impl Fn(i32) -> i32 {
    let i = 2;
    move |j| j * i
}

fn main() {
    let result = two_times_impl();

    assert_eq!(4, result(2));
}