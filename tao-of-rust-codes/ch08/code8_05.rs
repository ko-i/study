fn main() {
    println!("{:?}", 'f'.is_digit(16));
    println!("{:?}", 'f'.to_digit(16));

    println!("{:?}", 'a'.is_lowercase());
    println!("{:?}", '道'.is_lowercase());

    println!("{:?}", 'A'.is_uppercase());
    println!("{:?}", '中'.is_uppercase());

    println!("{:?}", 'I'.to_lowercase());
    println!("{:?}", 'b'.to_uppercase());

    println!("{:?}", ' '.is_whitespace());
    println!("{:?}", '\u{A0}'.is_whitespace());
    println!("{:?}", '越'.is_whitespace());

    println!("{:?}", 'a'.is_alphabetic());
    println!("{:?}", '京'.is_alphabetic());
    println!("{:?}", '1'.is_alphabetic());

    println!("{:?}", '7'.is_alphanumeric());
    println!("{:?}", 'K'.is_alphanumeric());
    println!("{:?}", '藏'.is_alphanumeric());

    println!("{:?}", ' '.is_control());
    println!("{:?}", 'q'.is_control());

    println!("{:?}", '7'.is_numeric());

}