fn main() {
    let n = 13;

    let big_n = if n < 10 && n > -10 {
        10 * n
    } else {
        n / 2
    };

    assert_eq!(6, big_n);
}