fn main() {
    let text = "  Poines  \n   giraffes\niguanas  \nsquid".to_string();
    let v: Vec<String> = text.lines().map(str::trim).map(str::to_string).collect();
    println!("{:?}", v);

    let text = "  Poines  \n   giraffes\niguanas  \nsquid".to_string();
    let v: Vec<&str> = text.lines().map(str::trim).filter(|s| *s != "iguanas").collect();
    println!("{:?}", v);
}