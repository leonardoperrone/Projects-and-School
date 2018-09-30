import { Component, ElementRef, OnInit, ViewChild } from '@angular/core';
import { ToastrService } from 'ngx-toastr';

@Component({
  selector: 'app-about',
  templateUrl: './about.component.html',
  styleUrls: ['./about.component.scss', '../../app.component.scss']
})
export class AboutComponent implements OnInit {
  @ViewChild('email') email: ElementRef;
  @ViewChild('copy') copy: ElementRef;

  public first = '';
  public last = '';
  public isCollapsed = true;
  public showButtonText = 'Show Email';

  constructor(private toastr: ToastrService) {
  }

  ngOnInit() {
  }

  public showEmail() {
    this.isCollapsed = !this.isCollapsed;
    if (!this.isCollapsed) {
      this.first = 'leonardoperrone1994';
      this.last = 'gmail.com';
    } else {
      this.showButtonText = 'Show Email';
    }
  }

  public showSuccess() {
    this.toastr.success('Email copied to clipboard!', 'Success!');
  }

  public showError() {
    this.toastr.error('Something went wrong. Please press Ctrl+C to copy!', 'Oops!');
  }

  public copyEmail() {

    this.email.nativeElement.select();
    try {
      document.execCommand('copy');

      this.showSuccess();
      // this.email.nativeElement.blur();

    } catch (err) {
      this.showError();
    } finally {
      setTimeout(() => {
        this.copy.nativeElement.blur();
      }, 1000);
    }
  }


}
