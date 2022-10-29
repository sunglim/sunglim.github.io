* Map

    var m map[int]string
 
    m = make(map[int]string)
    //추가 혹은 갱신
    m[901] = "Apple"
    m[134] = "Grape"
    m[777] = "Tomato"


    val, exists := tickers["MSFT"]
    if !exists {
        println("No MSFT ticker")
    }
