fn main() {
    let s = "Lowe 老 Leopard";

    let v = s.split(|c| (c as u32) >= (0x4E00 as u32) && (c as u32) <= (0x9FA5 as u32)).collect::<Vec<&str>>();
    println!("{:?}", v);

    let v = "abc1defXghi".split(|c| c == '1' || c == 'X').collect::<Vec<&str>>();
    println!("{:?}", v);

    let v = "Mary has a little lambda".splitn(3, ' ').collect::<Vec<&str>>();
    println!("{:?}", v);

    let v = "A.B.".split(".").collect::<Vec<&str>>();
    println!("{:?}", v);

    let v = "A.B.".split_terminator(".").collect::<Vec<&str>>();
    println!("{:?}", v);

    let v = "A..B..".split(".").collect::<Vec<&str>>();
    println!("{:?}", v);

    let v = "A..B..".split_terminator(".").collect::<Vec<&str>>();
    println!("{:?}", v);
}