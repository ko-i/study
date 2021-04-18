fn main() {
    let mut b = [0; 3];
    let tao = '道';

    let tao_str = tao.encode_utf8(&mut b);

    println!("{:?}", tao_str);
    println!("{:?}", tao.len_utf8());
}