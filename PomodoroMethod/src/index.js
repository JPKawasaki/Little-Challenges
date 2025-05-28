//Code for Pomodoro Timer

document.addEventListener('DOMContentLoaded', () => {
    const minutes = document.getElementById('minutes');
    const seconds = document.getElementById('seconds');
    const startBtn = document.getElementById('start');
    const resetBtn = document.getElementById('reset');
    const pomodoroCounter = document.getElementById('pomodoros');

    const soundWork = new Audio('../Sounds/mixkit-cinematic-transition-swoosh-heartbeat-trailer-488.wav');
    const soundBreak = new Audio('../Sounds/mixkit-cool-impact-movie-trailer-2909.wav');
    const soundRound = new Audio('../Sounds/mixkit-movie-trailer-epic-impact-2908.wav');
    
    
    let totalSecondsWork = 25 * 60;
    let totalSecondsBreak = 5 * 60;
    let currentSeconds = totalSecondsWork;
    let isBreak = false;
    let intervalId;
    let counter = 0;

    function updateTime(total) {
        const mins = Math.floor(total / 60);
        const secs = total % 60;
        minutes.textContent = String(mins).padStart(2, '0');
        seconds.textContent = String(secs).padStart(2, '0');
    };

    startBtn.addEventListener("click", () => {
        if (intervalId) return;

        soundWork.play();

        intervalId = setInterval(() => {
            if (currentSeconds > 0) {
                currentSeconds--;
                updateTime(currentSeconds);
            } else {
                isBreak = !isBreak;

                if (isBreak) {
                    currentSeconds = totalSecondsBreak;
                    soundBreak.play();
                } else {
                    currentSeconds = totalSecondsWork;
                    counter++;
                    pomodoroCounter.textContent = `Pomodoros completed: ${counter}`;
                    soundRound.play();
                }

                updateTime(currentSeconds);
            }
        }, 1000);
    });

    resetBtn.addEventListener("click", () => {
        console.log("Reset clicked. IntervalId before clear:", intervalId);
        if (intervalId) {
            clearInterval(intervalId);
            intervalId = null;
            console.log("Interval cleared.");
        } else {
            console.log("No interval to clear.");
        }

        totalSecondsWork = 25 * 60;
        totalSecondsBreak = 5 * 60;
        currentSeconds = totalSecondsWork;
        isBreak = false;
        counter = 0;
    
        pomodoroCounter.textContent = `Pomodoros completed: ${counter}`;
        updateTime(currentSeconds);
    });

    updateTime(currentSeconds);
})