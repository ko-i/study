fn main() {
    let num = 42u32;
    let num: u32 = 42;
    let num = 0x2A;
    let num = 0o106;
    let num = 0b1011_1011;

    assert_eq!(42u8, b'*');
    assert_eq!(39u8, b'\'');

    let num = 3.1415926f64;
    assert_eq!(-3.14, -3.14f64);
    assert_eq!(2., 2.0f64);
    assert_eq!(2e4, 20000f64);
    println!("{:?}", std::f32::INFINITY);
    println!("{:?}", std::f32::NEG_INFINITY);
    println!("{:?}", std::f32::NAN);
    println!("{:?}", std::f32::MIN);
    println!("{:?}", std::f32::MAX);
}