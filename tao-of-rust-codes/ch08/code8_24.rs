fn main() {
    println!("{:?}", "Hello\tworld\t".trim_matches('\t'));
    println!("{:?}", "11foo1bar".trim_matches('1'));
    println!("{:?}", "123foo1bar123".trim_matches(char::is_numeric));

    let x: &[char] = &['1', '2'];
    println!("{:?}", "12foo1bar12".trim_matches(x));

    println!("{:?}", "1foobarXX".trim_matches(|c| c == '1' || c == 'X'));

    println!("{:?}", "11foo1bar11".trim_start_matches('1'));

    println!("{:?}", "123foo1bar123".trim_start_matches(char::is_numeric));

    let x: &[char] = &['1', '2'];
    println!("{:?}", "12foo1bar12".trim_start_matches(x));

    println!("{:?}", "1fooX".trim_end_matches(|c| c == '1' || c == 'X'));
}