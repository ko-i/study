/// # 文档注释：Sum函数
/// 该函数为求和函数
/// # usage：
/// assert_eq!(3, sum(1, 2));
fn sum(a: i32, b: i32) -> i32 {
    a + b
}

fn main() {
    // 这是单行注释的示例

    /*
    ** 这是区块注释，被包含的区域都会被注释
    ** 你可以把/* 区块 */ 置于代码的任何位置
    */

    /* 
    注意上面区块注释中的**符号纯粹是一种注释风格，实际并不需要
    */

    let x = 5 + /* 90 + */ 5;
    assert_eq!(10, x);
    println!("2 + 3 = {}", sum(2, 3));
}