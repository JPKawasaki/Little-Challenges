//Code for Pomodoro Timer

document.addEventListener('DOMContentLoaded', () => {
    const minutes = document.getElementById('minutes');
    const seconds = document.getElementById('seconds');
    const startBtn = document.getElementById('start');
    const resetBtn = document.getElementById('reset');
    const pomodoroCounter = document.getElementById('pomodoros');
    
    const workingCat = document.getElementById('workingCat');
    const sleepingCat = document.getElementById('sleepingCat');

    const soundWork = new Audio('../Sounds/mixkit-cinematic-transition-swoosh-heartbeat-trailer-488.wav');
    const soundBreak = new Audio('../Sounds/mixkit-cool-impact-movie-trailer-2909.wav');
    const soundRound = new Audio('../Sounds/mixkit-movie-trailer-epic-impact-2908.wav');

    let totalSecondsWork = 25 * 60;
    let totalSecondsBreak = 5 * 60;
    let totalLongBreak = 15 * 60;
    let longerBreak;
    let isBreak = false;
    let intervalId = null;
    let counter = 0;

    let startTime = null;
    let duration = totalSecondsWork * 1000;

    function updateTime(total) {
        const mins = Math.floor(total / 60);
        const secs = total % 60;
        minutes.textContent = String(mins).padStart(2, '0');
        seconds.textContent = String(secs).padStart(2, '0');
    };

    function startCycle() {
        duration = (isBreak ? totalSecondsBreak : totalSecondsWork) * 1000;
        startTime = Date.now();
    
        if (!intervalId) {
            // Sound passend zur Phase abspielen
            if (isBreak) {
                soundBreak.play();
                workingCat.style.display = "none";
                sleepingCat.style.display = "inline-block";
            } else {
                soundWork.play();
                sleepingCat.style.display = "none";
                workingCat.style.display = "inline-block";
            }
    
            intervalId = setInterval(() => {
                const elapsed = Date.now() - startTime;
                const remainingMs = duration - elapsed;
                if (remainingMs <= 0) {
                    clearInterval(intervalId);
                    intervalId = null;
    
                    // Umschalten der Phase **vor** nächstem Zyklusstart
                    isBreak = !isBreak;
    
                    if (!isBreak) {  // wenn wir wieder in Arbeit wechseln (Pause beendet)
                        counter++;
                        pomodoroCounter.textContent = `Pomodoros completed: ${counter}`;
                        soundRound.play();
                    }
    
                    updateTime(0);
                    startCycle();
                } else {
                    updateTime(Math.ceil(remainingMs / 1000));
                }
            }, 250);
        }
    }

    startBtn.addEventListener("click", () => {
        if (!intervalId) {
            startCycle();
        }
    });

    resetBtn.addEventListener("click", () => {
        if (intervalId) {
            clearInterval(intervalId);
            intervalId = null;
        }
        isBreak = false;
        counter = 0;
        workingCat.style.display = "none";
        sleepingCat.style.display = "inline-block";
        pomodoroCounter.textContent = `Pomodoros completed: ${counter}`;
        updateTime(totalSecondsWork);
    });

    updateTime(totalSecondsWork);
});