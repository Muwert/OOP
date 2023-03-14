class Program
{
    static void Main(string[] args)
    {
        Nail nail1 = new SnyatiePokritiya();
        nail1 = new Kamyflyash(nail1); // снятие покрытия, камуфляж
        Console.WriteLine("Название: {0}", nail1.Name);
        Console.WriteLine("Цена: {0}", nail1.GetCost());

        Nail nail2 = new SnyatiePokritiya();
        nail2 = new Color(nail2);// снятие покрытия, покрытие цветом
        Console.WriteLine("Название: {0}", nail2.Name);
        Console.WriteLine("Цена: {0}", nail2.GetCost());

        Nail nail3 = new SnyatiePokritiya();
        nail3 = new Kamyflyash(nail3);
        nail3 = new Color(nail3);// снятие покрытия, камуфляж, покрытие цветом
        Console.WriteLine("Название: {0}", nail3.Name);
        Console.WriteLine("Цена: {0}", nail3.GetCost());

        Console.ReadLine();
    }
}

abstract class Nail
{
    public Nail(string n)
    {
        this.Name = n;
    }
    public string Name { get; protected set; }
    public abstract int GetCost();
}

class SnyatiePokritiya : Nail
{
    public SnyatiePokritiya() : base("Снятие покрытия")
    { }
    public override int GetCost()
    {
        return 600;
    }
}
class ManicurBezPokritiya : Nail
{
    public ManicurBezPokritiya()
        : base("Маникюр без покрытия")
    { }
    public override int GetCost()
    {
        return 900;
    }
}

class SnyatiePokritiyaAndGigienicheskiyManicur : Nail
{
    public SnyatiePokritiyaAndGigienicheskiyManicur()
        : base("Полное снятие покрытия и гигиенический маникюр")
    { }
    public override int GetCost()
    {
        return 1200;
    }
}
abstract class NailDecoratorPocritie : Nail
{
    protected Nail nail;
    public NailDecoratorPocritie(string n, Nail nail) : base(n)
    {
        this.nail = nail;
    }
}

class Kamyflyash : NailDecoratorPocritie
{
    public Kamyflyash(Nail p)
        : base(p.Name + ", камуфляж", p)
    { }

    public override int GetCost()
    {
        return nail.GetCost() + 1000;
    }
}

class Color : NailDecoratorPocritie
{
    public Color(Nail p)
        : base(p.Name + ", покрытие цветом", p)
    { }

    public override int GetCost()
    {
        return nail.GetCost() + 1200;
    }
}
