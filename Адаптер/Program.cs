class Program
{
    static void Main(string[] args)
    {
        // кран
        kran kran = new kran();
        // вода
        water water = new water();
        // вода отправляется в путешествие по крану
        kran.Travel(water);
        // встретился конец крана, надо использовать кота
        cat cat = new cat();
        // используем адаптер
        Iwater catWater = new CatToIwatertAdapter(cat);
        // кот пьёт воду
        kran.Travel(catWater);

        Console.Read();
    }
}
interface Iwater
{
    void run();
}
// класс воды
class water : Iwater
{
    public void run()
    {
        Console.WriteLine("Вода бежит по крану.");
    }
}
class kran
{
    public void Travel(Iwater water)
    {
        water.run();
    }
}
// интерфейс животного
interface IAnimal
{
    void Drink();
}
// класс кота
class cat : IAnimal
{
    public void Drink()
    {
        Console.WriteLine("Кот пьёт воду из под крана.");
    }
}
// Адаптер от cat к Iwater
class CatToIwatertAdapter : Iwater
{
    cat cat;
    public CatToIwatertAdapter(cat c)
    {
        cat = c;
    }

    public void run()
    {
        cat.Drink();
    }
}