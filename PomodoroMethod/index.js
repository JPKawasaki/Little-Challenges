//Code for Pomodoro Timer

document.addEventListener('DOMContentLoaded', () => {
    const minutes = document.getElementById('minutes');
    const seconds = document.getElementById('seconds');
    const startBtn = document.getElementById('start');
    const resetBtn = document.getElementById('reset');
    const pomodoroCounter = document.getElementById('pomodoro');
    const soundWork = new Audio('Sounds/mixkit-cinematic-transition-swoosh-heartbeat-trailer-488.wav');
    const soundBreak = new Audio('Sounds/mixkit-cool-impact-movie-trailer-2909.wav');
    const soundRound = new Audio('Sounds/mixkit-movie-trailer-epic-impact-2908.wav');
    
    
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

    startBtn.addEventListener("click", function() {
        soundWork.play();
        if (intervalId) return;

        intervalId = setInterval(() => {
            if (currentSeconds > 0) {
                currentSeconds--;
                updateTime(currentSeconds);
            } else {
                soundBreak.play();
                isBreak = !isBreak;

                if (isBreak) {
                    currentSeconds = totalSecondsBreak;
                } else {
                    currentSeconds = totalSecondsWork
                }
                updateTime(currentSeconds);
                counter++;
                pomodoroCounter.innerContent = `Pomodoros completed: ${counter}`
            }
        }, 1000);
    })

    resetBtn.addEventListener("click", function() {
        clearInterval(intervalId);
        intervalId = null;
        totalSecondsWork = 25 * 60;
        totalSecondsBreak = 5 * 60;
        currentSeconds = totalSecondsWork;
        isBreak = false;
        updateTime(currentSeconds);
    })
    updateTime(currentSeconds);
})