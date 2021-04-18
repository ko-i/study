fn main() {
    let packed = "Helen of Troy";
    let spaced = "Helen   of   Troy";
    let obscure = "Helen of Sandusky";

    println!("{:?}", packed != spaced);
    println!("{:?}", packed.split_whitespace().eq(spaced.split_whitespace()));

    println!("{:?}", spaced < obscure);
    println!("{:?}", spaced.split_whitespace().gt(obscure.split_whitespace()));
}