# Mutex and Channel basics

### What is an atomic operation?
> En operasjon eller sett med operasjoner som ikke kan avbrytes når de først har inntruffet. Eks, skrive til et register, lese en verdi eller lignende. 

### What is a semaphore?
> En mekanisme som tillater hvor mange som skal ha tilgang til et område eller lignende. Krever i de fleste tilfelle et syscal. 

### What is a mutex?
> En mekanisme som beskytter et område, for eksempel minne, og sørger for at kun en task har tilgang til området om gangen. 

### What is the difference between a mutex and a binary semaphore?
> En mutex kan kun låses opp av samme task som låste den, mens en semafor kan også andre tasks kalle signal kommandoen, og med det frigjøre området. 

### What is a critical section?
> Innenfor informatikken er en kritisk region eller en kritisk seksjon en beskyttet seksjon i et dataprogram som bare kan utføres av en enkelt prosess av gangen. Problemet er aktuelt innenfor parallelle beregninger hvor en delt ressurs kan føre til uventet eller feilaktig adferd, hvis den ikke blir beskyttet

### What is the difference between race conditions and data races?
 > Data race er skjer når to tasks skriver til samme minneområde uten bruk av en beskyttelsesmekansime som mutex eller semafor. 
 
 > Race condition er mer generelt når et porgrams korrekte utførelse er avhengig av timing eller at hendelser skjer i en spesiell rekkefølge. Data race er en spesiell form for race condition?

### List some advantages of using message passing over lock-based synchronization primitives.
> I message passing unngår man deadlocks, men man kan få utdaterte verdier. Skalerer stort sett bedre.

### List some advantages of using lock-based synchronization primitives over message passing.
> Kan oppstå deadlock, men man er garantert oppdatert verdi, skalerer stort sett ddårligere enn message passing.
