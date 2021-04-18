fn main() {
    let x = 'r';

    println!("{:?}", '\'');
    println!("{:?}", '\\');
    println!("{:?}", '\n');
    println!("{:?}", '\r');
    println!("{:?}", '\t');
    
    assert_eq!('\x2A', '*');
    assert_eq!('\x25', '%');

    assert_eq!('%' as i8, 37);
}