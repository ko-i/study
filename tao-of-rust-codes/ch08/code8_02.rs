fn main() {
    let tao = '道';
    let tao_u32 = tao as u32;
    println!("{:?}", tao_u32);

    println!("U+{:x}", tao_u32);
    println!("{}", tao.escape_unicode());

    println!("{:?}", char::from(65));
    println!("{:?}", std::char::from_u32(0x9053));
    println!("{:?}", std::char::from_u32(36947));
    println!("{:?}", std::char::from_u32(12901010));
}