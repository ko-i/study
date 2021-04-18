use std::str;

fn main() {
    let tao = str::from_utf8(&[0xE9u8, 0x81u8, 0x93u8]).unwrap();

    println!("{:?}", tao);
    println!("{:?}", String::from("\u{9053}"));

    let unicode_x = 0x9053;
    let utf_x_hex = 0xe98139;
    let utf_x_bin = 0b111010011000000110010011;

    println!("unicode_x: {:b}", unicode_x);
    println!("utf_x_hex: {:b}", utf_x_hex);
    println!("utf_x_bin: {:b}", utf_x_bin);
}